# Re:VIEW+CSS組版 執筆環境構築

Re:VIEW+CSS組版の執筆環境を構築できます。

## git clone

```shell
$ git clone -b v0.2.0 git@github.com:at-grandpa/review-and-css-typesetting.git
```

## 説明書PDF

説明書のPDFのリンクは以下です（リリースページにあるPDFのリンクです）。セットアップの方法や執筆の進め方などが記載されています。

[説明書PDF](https://github.com/at-grandpa/review-and-css-typesetting/releases/download/v0.2.0/book.pdf)

このPDFはサンプルPDFの役割も果たしています。このリポジトリ直下で `make setup` と `make pdf` を実行すれば、`./articles/book.pdf` に同様のものが出力されます。 実際にCSS組版を適用したものになっているので、試行錯誤の材料としてご利用ください。

## 動作環境

下記のものがインストールされている状態で動作確認をしています。

```shell
$ sw_vers | grep Product
ProductName:    Mac OS X
ProductVersion: 10.13.6

$ docker -v
Docker version 18.09.1, build 4c52b90

$ docker-compose -v
docker-compose version 1.23.2, build 1110ad01

$ make -v
GNU Make 3.81
```

## コマンド一覧

よく使うコマンドは以下です。

* `make setup` で環境が整う
* `make pdf` で `./articles/book.pdf` にPDF出力
* `make browser` でブラウザ確認ができ、DevToolsなどでCSSの調整ができる
* `make lint` でtextlintとprhによるlintをかける

その他のコマンドは `make` もしくは `make help` で見ることができます。
```shell
$ make help

    review-and-css-typesetting

    usage: make [command]

    help       ヘルプを表示
    args       デフォルトの変数を表示する
    setup      docker環境をセットアップする
    build      dockerイメージをbuildする
    up         dockerコンテナを立ち上げる
    clean      dockerコンテナを停止して削除する
    stop       dockerコンテナを停止する
    rm         dockerコンテナを削除する
    ps         dockerコンテナ一覧を表示する
    login      dockerコンテナ内にログインする
    init       ./article配下を削除して、review-initで./articlesを再生成する
    html       htmlを生成する (./articles/book.html)
    pdf        PDFを生成する (default: ./articles/book.pdf) (出力先変更: make pdf PDF=./hoge.pdf)
    browser    ブラウザで表示する (vivliostyle経由)
    lint       textlint, prhでlintをかける
    lint/fix   prhの指摘点を自動修正する

```

## ライブラリのバージョン

* `Re:VIEW` : 3.1
* `Vivliostyle` : 2018.12.103

## circleci

`.circleci/config.yml` に設定が書かれています。
`make lint` と `make pdf` が実行され、エラーがないかチェックしています。
Artifacts として `book.pdf` がダウンロードできます。

## フィードバック

ISSUEやPRは大歓迎です。よりよいRe:VIEW+CSS組版の環境を目指しましょう！
