include ./args.mk

# ===================================================
# setup
# ===================================================

setup_npm:
	npm install --unsafe-perm

setup_bundler:
	bundle install --path vendor/bundle

# ===================================================
# status check
# ===================================================

status_check_url:
	@chmod -x ./docker_env/status_check.sh
	@/bin/sh ./docker_env/status_check.sh $(URL)

status_check/review:
	@$(MAKE) status_check_url -f in_docker.mk URL=http://0.0.0.0:8989/

status_check/vivliostyle:
	@$(MAKE) status_check_url -f in_docker.mk URL=http://0.0.0.0:8000/

status_check: status_check/review status_check/vivliostyle

# ===================================================
# create command
# ===================================================

init:
	rm -rf ./articles
	review-init articles

html:
	cd articles/ && review-epubmaker config.yml && review-epub2html book.epub | bundle exec ruby ../scripts/html-ext.rb > book.html
	@$(MAKE) status_check -f in_docker.mk --no-print-directory

pdf: html
	node docker_env/pdf.js $(PDF) $(HTML_URL) $(PAGE_FORMAT)

# ===================================================
# lint
# ===================================================

lint:
	npx textlint $(TEXTLINT_OPTIONS) $(LINT_TARGET_FILES)

lint/fix:
	$(MAKE) lint -f in_docker.mk TEXTLINT_OPTIONS=--fix LINT_TARGET_FILES='$(LINT_TARGET_FILES)'
