= 独自設定の説明

//imagetalkl[grandpa]{
だいたいわかったかの？
//}

//imagetalkr[mago]{
うん！わかったー！だけど、デザインに凝りすぎるのもよく無いね。気をつけよー。
//}

//imagetalkl[grandpa]{
そうじゃな。あくまでも内容が一番大切じゃ。
//}

//imagetalkr[mago]{
次はなんの説明なの？
//}

//imagetalkl[grandpa]{
次は、このリポジトリの独自設定の説明じゃ。Re:VIEWの拡張など、少し特殊なことをやっておる。その説明をするぞい。
//}

//imagetalkr[mago]{
はーい！
//}

//pagebreak

さて、次はグランパのいうとおり「このリポジトリの独自設定」を説明します。
編集の参考にしてみてください。

== 大扉のデザイン

大扉のデザインは、自分のCSS力では難しかった（CSSだけで表現できなかった）ので、Rubyのライブラリ @<code>{Nokogiri} を用いてhtmlを編集しています。
@<code>{in_docker.mk} の次の部分がhtml生成箇所です。

//emlist[][]{
html:
	cd articles/ && \
		review-epubmaker config.yml && \
		review-epub2html book.epub | \
		bundle exec ruby ../scripts/html-ext.rb > book.html
//}

 * @<code>{config.yml} をもとにepubを生成
 * @<code>{review-epub2html} でepubをひとつのhtmlに変換
 * @<code>{./scripts/html-ext.rb} を通してhtmlタグを修正
 * htmlに出力

必要なhtml要素が準備できたら、後はCSSを編集するだけです。
@<code>{./articles/style.css} も参考にしてみてください。

また、これらのデザインを決める際は @<code>{make browser} を用いてブラウザに表示し、CSSを直接いじって試行錯誤を繰り返しました。

== 目次のデザイン

これも大扉の場合と同じです。
@<code>{./scripts/html-ext.rb} を用いて目次部分に必要なhtmlタグを追加し、CSSでデザインを適用しています。

== 見出しのデザイン

こちらは純粋にCSSだけで実現しています。
生成される @<code>{./article/book.html} の中身をみて、いろいろ試行錯誤しました。
お好きな形に変更していただいてかまいません。

== 「コラム」や「問題」「答え」のデザイン

「コラム」や「問題」「答え」のデザインは、Re:VIEWの公式の拡張 @<code>{./articles/review-ext.rb} を使っています。
拡張に関しては、次の「Re:VIEW のモンキーパッチによる拡張の基本」と @<code>{./articles/review-ext.rb} を参考にしてください。

 * Re:VIEW のモンキーパッチによる拡張の基本
 ** https://review-knowledge-ja.readthedocs.io/ja/latest/reviewext/review-ext-basic.html

拡張したコマンドによって生成されたhtmlに対し、CSSを適用しています。
もちろん、色やマージンなどの微調整も可能です。

===[mycolumn] コラム

//emlist[]{
===[mycolumn] コラム

こんな感じでコラムを書いています。

===[/mycolumn]
//}

==== 見出しも書けます

見出しも書けていますね。

===[/mycolumn]

===[question] 問題

これは問題です。次のように書いています。

//emlist[]{
===[question] 問題だよ

これは問題です。以下のように書いています。

===[/question]
//}

キャプションの文字列は「問題だよ」のように任意の文字列を設定できます。

===[/question]

===[answer] 答えだよ

これは答えです。「問題」と同様、キャプションの文字列は自由に設定できます。

//emlist[]{
===[answer] 答えだよ

これは答えです。「問題」と同様、キャプションの文字列は自由に設定できます。

===[/answer]
//}

===[/answer]

//pagebreakforce

== 吹き出しのデザイン

//imagetalkl[grandpa]{
左側の吹き出しじゃ。
//}

//imagetalkr[mago]{
右側の吹き出しだよー！
//}

//imagetalkl[grandpa]{
長文にも対応しておるぞ。長文にも対応しておるぞ。長文にも対応しておるぞ。長文にも対応しておるぞ。長文にも対応しておるぞ。長文にも対応しておるぞ。長文にも対応しておるぞ。長文にも対応しておるぞ。長文にも対応しておるぞ。長文にも対応しておるぞ。長文にも対応しておるぞ。長文にも対応しておるぞ。
//}

//imagetalkr[mago]{
改行にも対応しているよ！
改行にも対応しているよ！
改行にも対応しているよ！
改行にも対応しているよ！
改行にも対応しているよ！
//}

前回の技術書典にて頒布した本で、一番やりたかったことです。
こちらもRe:VIEWの公式の拡張 @<code>{./articles/review-ext.rb} を使っています。
次の独自コマンドを作成し、 @<code>{.re} ファイルで使用しています。

 * @<code>{imagetalkl（image-talk-left）}
 * @<code>{imagetalkr（image-talk-right）}

@<code>{*.re} ファイルで使用している箇所があるので探してみてください。

//pagebreakforce

ひとつ注意点があります。
RE:VIEWでは、同じ画像ファイルを複数回使うと「警告：画像IDが重複しています」と出力されます。

//cmd{
WARN: warning: duplicate ID: grandpa (#<ReVIEW::Book::ImageIndex::Item:0x0055e62fb5fd18>)
WARN: warning: duplicate ID: grandpa (#<ReVIEW::Book::ImageIndex::Item:0x0055e62f52ef20>)
WARN: warning: duplicate ID: mago (#<ReVIEW::Book::ImageIndex::Item:0x0055e62f52edb8>)
WARN: warning: duplicate ID: grandpa (#<ReVIEW::Book::ImageIndex::Item:0x0055e62f52ec28>)
WARN: warning: duplicate ID: mago (#<ReVIEW::Book::ImageIndex::Item:0x0055e62f52ea98>)
//}

最終生成物には影響はありませんでした。
気になる方はPRをいただけると幸いです。
