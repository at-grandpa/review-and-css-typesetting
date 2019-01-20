require "nokogiri"

class HtmlExtension
  attr_reader :html

  def initialize(html)
    @html = html
  end

  def run
    toc_design
    titlepage_design
    self
  end

  def toc_design
    # 目次の点線を表現するための<span>タグを追加
    toc_list = @html.css('nav li a')
    unless toc_list.empty?
      toc_list.each do |a|
        span = Nokogiri::XML::Node::new('span', a)
        a.add_child(span)
      end
    end
  end

  def titlepage_design
    # 大扉をいい感じに整形するための処理
    author = html.css('div.titlepage h2.tp-author').inner_text
    publisher = html.css('div.titlepage h3.tp-publisher').inner_text

    subtitle = html.at_css('section#s_book h2.cover-subtitle')
    return if subtitle.nil?

    cover_author = subtitle.add_next_sibling "<h2 class=\"cover-author\">#{author}</h2>"
    cover_author.first.add_next_sibling "<h3 class=\"cover-publisher\">#{publisher}</h2>"

    html.css('div.titlepage h1.tp-title').remove
    html.css('div.titlepage h2.tp-subtitle').remove
    html.css('div.titlepage h2.tp-author').remove
    html.css('div.titlepage h3.tp-publisher').remove
  end
end

html_ext = HtmlExtension.new(Nokogiri::HTML(STDIN))
puts html_ext.run.html
