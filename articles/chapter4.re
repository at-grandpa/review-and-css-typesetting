= テストページ

//imagetalkr[mago]{
テストページって何？
//}

//imagetalkl[grandpa]{
ここは、動作確認のために使うページじゃぞい。
//}

//imagetalkr[mago]{
へー。何の動作確認なの？
//}

//imagetalkl[grandpa]{
コードの埋め込みやPlantUMLの描画などじゃ。
//}

//imagetalkr[mago]{
ふーん。
//}

//pagebreak

== コードの埋め込み

Re:VIEWには外部ファイルを埋め込む機能があります。

//emlist[コードの埋め込み][crystal]{
#@mapfile(../code/sample.cr)
class Foo
  def display(str : String)
    puts str
  end
end

foo = Foo.new
foo.display("Hello!!") # => Hello!!
#@end
//}

このコードは @<code>{./code/sample.cr} に書かれているものです。
@<code>{review-preproc --replace *.re} のコマンドを実行し、 @<code>{*.re} 内に書かれている @<code>{@mapfile} 命令を置換します。

== PlantUML

Re:VIEWは @<code>{glaph} 命令でPlantUMLを描画できます。
次のコードを @<code>{glaph} 命令に書くことで、次のような図を埋め込むことができます。

//list[sample_uml_code][PlantUMLのコード]{
@startuml
Foo .r.> Bar

class Foo {
    + display() : Nil
}

class Bar {
    + display() : Nil
}
@enduml
//}

//graph[sample_uml_graph][plantuml][PlantUMLの描画]{
@startuml
Foo .r.> Bar

class Foo {
    + display() : Nil
}

class Bar {
    + display() : Nil
}
@enduml
//}

この他、できることが分かり次第、随時追加していきます。
