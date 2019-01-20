# encoding: utf-8
ReVIEW::Compiler.defblock :imagetalkl, 1..2
ReVIEW::Compiler.defblock :imagetalkr, 1..2
ReVIEW::Compiler.defsingle :mycolumnbegin, 0
ReVIEW::Compiler.defsingle :mycolumnend, 0
ReVIEW::Compiler.defsingle :questionbegin, 0
ReVIEW::Compiler.defsingle :questionend, 0
ReVIEW::Compiler.defsingle :answerbegin, 0
ReVIEW::Compiler.defsingle :answerend, 0
ReVIEW::Compiler.defsingle :pagebreakforce, 0

class ReVIEW::HTMLBuilder
  def imagetalkl(lines, img_id, metric=nil)
    body = lines.map{|line| line + "<br />"}

    puts "<!--吹き出しはじまり-->"
    puts "<div class=\"balloon_l\">"
    puts "  <div class=\"faceicon_l_bg\">"
    puts "    <div class=\"faceicon_l\">"
    indepimage('', img_id)
    puts "    </div>"
    puts "  </div>"
    puts "  <div class=\"chatting\">"
    puts "    <div class=\"says_l\">"
    puts body
    puts "    </div>"
    puts "  </div>"
    puts "</div>"
    puts "<!--吹き出し終わり-->"
  end

  def imagetalkr(lines, img_id, metric=nil)
    body = lines.map{|line| line + "<br />"}

    puts "<!--吹き出しはじまり-->"
    puts "<div class=\"balloon_r\">"
    puts "  <div class=\"faceicon_r_bg\">"
    puts "    <div class=\"faceicon_r\">"
    indepimage('', img_id, '', metric)
    puts "    </div>"
    puts "  </div>"
    puts "  <div class=\"chatting\">"
    puts "    <div class=\"says_r\">"
    puts body
    puts "    </div>"
    puts "  </div>"
    puts "</div>"
    puts "<!--吹き出し終わり-->"
  end

  def mycolumnbegin
    puts "<!--コラムはじまり-->"
    puts "<div class=\"my-column\">"
    puts "<span class=\"my-column-title\">コラム</span>"
  end

  def mycolumnend
    puts "</div>"
    puts "<!--コラムおわり-->"
  end

  def questionbegin
    puts "<!--問題はじまり-->"
    puts "<div class=\"question\">"
    puts "<span class=\"question-title\">問題</span>"
  end

  def questionend
    puts "</div>"
    puts "<!--問題おわり-->"
  end

  def answerbegin
    puts "<!--答えはじまり-->"
    puts "<div class=\"answer\">"
    puts "<span class=\"answer-title\">答え</span>"
  end

  def answerend
    puts "</div>"
    puts "<!--答えおわり-->"
  end

  def pagebreakforce
    puts "<div class=\"page-bleak-after\"></div>"
  end
end
