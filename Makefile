.PHONY: help

help: ## ヘルプを表示
	@echo ''
	@echo '    review-and-css-typesetting'
	@echo ''
	@echo '    usage: make [command]'
	@echo ''
	@grep -E '^[\/a-zA-Z_-]+:.*?## .*$$' ./Makefile | awk 'BEGIN {FS = ":.*?## "}; {printf "    \033[36m%-10s\033[0m %s\n", $$1, $$2}'
	@echo ''

include ./args.mk

args: ## デフォルトの変数を表示する
	@cat ./args.mk

# ===================================================
# Docker
# ===================================================
setup: build up docker/setup_npm docker/setup_bundler docker/setup_plantuml_jar ## docker環境をセットアップする

build: ## dockerイメージをbuildする
	$(DOCKER_COMPOSE) build \
		--build-arg VIVLIOSTYLE_VERSION=$(VIVLIOSTYLE_VERSION)

up: ## dockerコンテナを立ち上げる
	$(DOCKER_COMPOSE) up -d

clean: stop rm ## dockerコンテナを停止して削除する

stop: ## dockerコンテナを停止する
	$(DOCKER_COMPOSE) stop

rm: ## dockerコンテナを削除する
	$(DOCKER_COMPOSE) rm -f

ps: ## dockerコンテナ一覧を表示する
	$(DOCKER_COMPOSE) ps

login: ## dockerコンテナ内にログインする
	$(DOCKER_COMPOSE) exec review /bin/bash

docker/%:
	$(DOCKER_COMPOSE) exec review /bin/bash -ci "make $* -f in_docker.mk"

# ===================================================
# create command
# ===================================================

init: ## ./article配下を削除して、review-initで./articlesを再生成する
	$(DOCKER_COMPOSE) exec review /bin/bash -ci "make init -f in_docker.mk"

html: ## htmlを生成する (./articles/book.html)
	$(MAKE) docker/html

pdf: ## PDFを生成する (default: ./articles/book.pdf) (出力先変更: make pdf PDF=./hoge.pdf)
	$(DOCKER_COMPOSE) exec review /bin/bash -ci "make pdf -f in_docker.mk PDF=$(PDF) HTML_URL=$(HTML_URL) PAGE_FORMAT=$(PAGE_FORMAT)"
	open $(PDF)

browser: html ## ブラウザで表示する (vivliostyle経由)
	open $(HTML_URL)

# ===================================================
# lint
# ===================================================

lint: ## textlint, prhでlintをかける
	$(DOCKER_COMPOSE) exec review /bin/bash -ci "make lint -f in_docker.mk LINT_TARGET_FILES='$(LINT_TARGET_FILES)'"

lint/fix: ## prhの指摘点を自動修正する
	$(DOCKER_COMPOSE) exec review /bin/bash -ci "make lint/fix -f in_docker.mk LINT_TARGET_FILES='$(LINT_TARGET_FILES)'"
