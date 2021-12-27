require_relative 'ex03.rb'
require 'test/unit'
require 'colorize'

class MainTest < Test::Unit::TestCase
  def test_self
    assert_equal(1.to_s, "1" ," Always check your tools ")
  end
  def test_initialize_params
    body = Elem.new('body')
    assert_kind_of( Elem, body,"Devrais etre une instance d' Elem")
    assert_kind_of( Array, body.content,"Devrais etre une instance d' Array")
    assert_kind_of( Hash, body.opt,"Devrais etre une instance d' Hash")
    assert_equal(body.tag, "body" )
    assert_equal(body.tag_type, "double" )
    head = Elem.new('head')
    assert_kind_of( Elem, body,"Devrais etre une instance d' Elem")
    assert_kind_of( Array, body.content,"Devrais etre une instance d' Array")
    assert_kind_of( Hash, body.opt,"Devrais etre une instance d' Elem")
    assert_equal(head.tag, "head" )
    assert_equal(head.tag_type, "double" )
  end

  def test_initialize_params_2
    img = Elem.new('img', '', 'simple',{'src':'http://i.imgur.com/pfp3T.jpg'})
    assert_kind_of( Elem, img,"Devrais etre une instance d' Elem")
    assert_kind_of( Hash, img.opt,"Devrais etre une instance d' Hash")
    assert_equal(img.tag, "img" )
    assert_equal(img.tag_type, "simple" )
    assert_equal(img.opt[:src], "http://i.imgur.com/pfp3T.jpg" )
  end

  def test_to_s
    body = Elem.new('body')
    img = Elem.new('img', '', 'simple',{'src':'http://i.imgur.com/pfp3T.jpg'})
    assert(body.to_s,"<body>\n</body>")
    assert(img.to_s,"<img src='http://i.imgur.com/pfp3T.jpg' />")
  end

  def test_text
     h1 = Elem.new('h1',Text.new('"Oh no, not again!"'))
    assert_kind_of(Text, h1.content, "Devrais etre une instance de Text")
    assert_kind_of(Elem, h1, "Devrais etre une instance de Elem")
    assert_equal(h1.to_s, "<h1>\"Oh no, not again!\"</h1>")
 end
 def test_add_content
   body = Elem.new('body')
   head = Elem.new('head')
   h1 = Elem.new('h1',Text.new('"Oh no, not again!"'))
   title = Elem.new('title', Text.new('"Hello ground!"'))
   img = Elem.new('img', '', 'simple',{'src':'http://i.imgur.com/pfp3T.jpg'})
   html = Elem.new('html')
   head.add_content(title)
   body.add_content(h1, img)
   assert_kind_of(Array, body.content)
   assert_equal(body.content.count, 2)
   assert_kind_of(Elem, body.content[0])
   assert_kind_of(Text, body.content[0].content)
   assert_kind_of(Elem, body.content[1])
   assert_equal(body.to_s, "<body>\n<h1>\"Oh no, not again!\"</h1>\n<img src='http://i.imgur.com/pfp3T.jpg' />\n</body>")
   html.add_content(head, body)
   assert_kind_of(Array, html.content)
   assert_equal(html.to_s,"<html>\n<head>\n<title>\"Hello ground!\"</title>\n</head>\n<body>\n<h1>\"Oh no, not again!\"</h1>\n<img src='http://i.imgur.com/pfp3T.jpg' />\n</body>\n</html>" )
 end
end
