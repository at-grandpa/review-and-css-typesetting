= 環境構築と執筆の流れ

//imagetalkl[grandpa]{
さて、Re:VIEW+CSS組版の環境構築について説明するぞい。
//}

//imagetalkr[mago]{
わ！こんなところに私たちも登場していいの！？
//}

//imagetalkl[grandpa]{
いいんじゃよ！張り切って説明するぞい！
//}

//pagebreak

こんにちは。
@<code>{@at_grandpa}です。
今回は、Re:VIEW+CSS組版の開発環境についてお話します。マゴとグランパと一緒に進めていきましょう。
さっそく使い方を見ていきます。

== 動作環境

まずは動作環境です。
次の動作環境のみで確認をしています。
もし他の環境で問題が起こる場合は、自前で修正していただくか、issueを送っていただけますと幸いです。

//cmd{
$ sw_vers | grep Product
ProductName:    Mac OS X
ProductVersion: 10.13.6

$ docker -v
Docker version 18.09.1, build 4c52b90

$ docker-compose -v
docker-compose version 1.23.2, build 1110ad01

$ make -v
GNU Make 3.81
//}

#@# textlint-disable prh
== @<code>{git clone}
#@# textlint-enable prh

ではリポジトリのcloneを行いましょう。
次のコマンドをたたき、リポジトリのルートディレクトリへ移動します。

//cmd{
$ git clone https://github.com/at-grandpa/review-and-css-typesetting.git
$ cd review-and-css-typesetting
//}

個々人のリポジトリで使用する場合、cloneしたディレクトリ群をコピーして使用してください。

== 執筆するファイルの配置場所

執筆するファイルの配置場所は @<code>{./articles} 以下です。
このディレクトリ内は、Re:VIEWのファイル配置規則にしたがってください。
@<code>{review-init} で生成されるディレクトリを @<code>{./articles} に置き換えていただければ大丈夫です。
もし最初から執筆を行う場合は、このあとに説明するコマンド @<code>{make init} を叩いてください。
このコマンドは、@<code>{./articles} ディレクトリ内を初期化（@<code>{review-init articles}を実行した状態）するコマンドです。

== コマンドの使い方

主なコマンドを見ていきましょう。
次のコマンドはすべてリポジトリルートで実行するコマンドです。

 * @<code>{make setup}
 ** Re:VIEW+CSS組版環境の構築を行う
 * @<code>{make init}
 ** @<code>{./articles} 内を初期化する
 * @<code>{make pdf}
 ** PDFを生成する
 * @<code>{make browser}
 ** vivliostyleを用いてブラウザで開く
 ** デベロッパーール等でCSSの確認ができる
 * @<code>{make lint}
 ** textlint, prh によるlint
 * @<code>{make lint/fix}
 ** prh の自動修正

リポジトリのclone後は @<code>{make setup} を叩いて環境を構築します。
環境を構築したら、 @<code>{make pdf}, @<code>{make browser}, @<code>{make lint} などを使用して執筆していきます。

その他のコマンドについてはhelpを参照してください。
@<code>{make} とたたくか @<code>{make help} とたたくことでhelpを表示できます。

//cmd{
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
    pdf        PDFを生成する (default: ./articles.book.pdf) (出力先変更: make pdf PDF=./hoge.pdf)
    browser    ブラウザで表示する (vivliostyle経由)
    lint       textlint, prhでlintをかける
    lint/fix   prhの指摘点を自動修正する

//}

== 執筆の流れ

続いて、具体的な執筆の流れを説明していきます。

=== @<code>{*.re} ファイルを書いていく

Re:VIEW記法で書く @<code>{*.re} ファイルは @<code>{./articles} ディレクトリに配置します。
このディレクトリの中に @<code>{catalog.yml} があるので、それに沿って書いていきます。
詳しくは、Re:VIEW本家のドキュメントを御覧ください。

=== ブラウザで内容を確認する

ある程度執筆したら、ブラウザで内容を確認しましょう。
@<code>{make browser} コマンドをたたくとブラウザで内容を確認できます（@<code>{open}コマンドでURLを叩いています。macOS限定です。環境によってMakefileを書き換えてください）。
vivliostyle経由で閲覧でき、Chrome DevTools などを用いればCSSの一時的な変更もできます。
微調整に最適です。

=== CSSを編集する

CSSファイルは @<code>{./articles/style.css} です。
このPDF生成の @<code>{style.css} は、vvakameさんのCSS組版リポジトリのファイルを参考にしています。
対象のhtmlは @<code>{./articles/book.html} です。
ブラウザでの確認をもとに、CSSファイルを編集していきましょう。
見た目の確認は @<code>{make browser} でもできますが、最終的にできあがるPDFとは若干デザインが異なるのでPDFの確認も行いましょう。

=== lintをかける

@<code>{make lint} でtextlintとprhを用いたlintをかけることができます。
デフォルトでは @<code>{./textlintrc} の設定を元にしています。
@<code>{preset-ja-technical-writing} や @<code>{period-in-list-item} のルールはすでにインストール済みです。
prhの設定に関しては、 @<code>{./prh-rules} ディレクトリに配置しています。
次のリポジトリを参考にさせていただきました。

 * https://github.com/prh/rules

適宜必要な設定に書き換えて使用してください。

=== PDFを生成する

PDF生成は @<code>{make pdf} コマンドです。
目次のリンクやURLのリンクも適用済みです。
@<code>{make browser} の結果とは若干異なるので、最終的なチェックはPDFで行いましょう。

=== circleciでPDF生成やlintをチェックする

@<code>{./.circleci/config.yml} にcircleciでの設定が書かれています。
lintとPDF生成を行っています。
必要であれば適宜書き換えてください。

=== フォントの埋め込みをする

印刷所に入稿するときは、PDFにフォントを埋め込まなければいけません。
自動で埋め込みができているとよいのですが現状できていません。
macOSの場合は @<code>{プレビュー.app} を用いて再度PDFに書き出すことでフォント埋め込みが可能です。
他の環境の方は、フォントの埋め込み方を調べて実施してください。

== ちょっとした注意点

自分自身が陥った罠なのですが、「デザインに凝ると時間が無限に必要」です。
まずは内容を完成させましょう。
最悪、デザインはシンプルでも内容が充実していれば伝わります。
逆に、デザインが良くても内容が不十分だと読者はがっかりします。
この順番は間違えないようにしてください。
#@# textlint-disable
（自分にも言い聞かせよう。。。）
#@# textlint-enable
