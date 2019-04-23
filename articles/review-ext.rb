# encoding: utf-8
ReVIEW::Compiler.defblock :imagetalkl, 1..2
ReVIEW::Compiler.defblock :imagetalkr, 1..2

# for backward compatibility
ReVIEW::Compiler.defsingle :mycolumnbegin, 0
ReVIEW::Compiler.defsingle :mycolumnend, 0
ReVIEW::Compiler.defsingle :questionbegin, 0
ReVIEW::Compiler.defsingle :questionend, 0
ReVIEW::Compiler.defsingle :answerbegin, 0
ReVIEW::Compiler.defsingle :answerend, 0

ReVIEW::Compiler.defsingle :pagebreakforce, 0

module HTMLBuilderOverride
  def imagetalkl(lines, img_id, metric=nil)
    body = lines.map {|line| "#{line}<br />"}.join

    puts <<EOT
<!--吹き出しはじまり-->
<div class="balloon_l">
  <div class="faceicon_l_bg">
    <div class="faceicon_l">
EOT
    indepimage('', img_id, '', metric)
    puts <<EOT
    </div>
  </div>
  <div class="chatting">
    <div class="says_l">
#{body}
    </div>
  </div>
</div>
<!--吹き出し終わり-->
EOT
  end

  def imagetalkr(lines, img_id, metric=nil)
    body = lines.map {|line| "#{line}<br />"}.join

    puts <<EOT
<!--吹き出しはじまり-->
<div class="balloon_r">
  <div class="faceicon_r_bg">
    <div class="faceicon_r">
EOT
    indepimage('', img_id, '', metric)
    puts <<EOT
    </div>
  </div>
  <div class="chatting">
    <div class="says_r">
#{body}
    </div>
  </div>
</div>
<!--吹き出し終わり-->
EOT
  end

  def mycolumn_begin(_level=nil, _label=nil, caption='コラム')
    puts <<EOT
<!--コラムはじまり-->
<div class="my-column">
<span class="my-column-title">#{caption}</span>
EOT
  end

  def mycolumn_end(_level=nil)
    puts <<EOT
</div>
<!--コラムおわり-->
EOT
  end

  def question_begin(_level=nil, _label=nil, caption='問題')
    puts <<EOT
<!--問題はじまり-->
<div class="question">
<span class="question-title">#{caption}</span>
EOT
  end

  def question_end(_level=nil)
    puts <<EOT
</div>
<!--問題おわり-->
EOT
  end

  def answer_begin(_level=nil, _label=nil, caption='答え')
    puts <<EOT
<!--答えはじまり-->
<div class="answer">
<span class="answer-title">#{caption}</span>
EOT
  end

  def answer_end(_level=nil)
    puts <<EOT
</div>
<!--答えおわり-->
EOT
  end

  alias_method :mycolumnbegin, :mycolumn_begin
  alias_method :mycolumnend, :mycolumn_end
  alias_method :questionbegin, :question_begin
  alias_method :questionend, :question_end
  alias_method :answerbegin, :answer_begin
  alias_method :answerend, :answer_end

  def pagebreakforce
    puts %Q(<div class="page-bleak-after"></div>)
  end
end

class ReVIEW::HTMLBuilder
  prepend HTMLBuilderOverride
end
