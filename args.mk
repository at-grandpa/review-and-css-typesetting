DOCKER_COMPOSE      := docker-compose -f ./docker_env/docker-compose.yml
DOCKER_EXEC         := docker exec -it
VIVLIOSTYLE_VERSION := 2018.12.103
LINT_TARGET_FILES   := $(shell find ./articles -type f -name '*.re')
PDF                 := ./articles/book.pdf
HTML_URL            := http://0.0.0.0:8000/vivliostyle-js-$(VIVLIOSTYLE_VERSION)/viewer/vivliostyle-viewer.html\#x=http://0.0.0.0:8989/book.html
PAGE_FORMAT         := A5
