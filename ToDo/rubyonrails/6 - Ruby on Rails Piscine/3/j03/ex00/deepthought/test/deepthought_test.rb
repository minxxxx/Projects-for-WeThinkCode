require 'test_helper'

class DeepthoughtTest < Minitest::Test

  def test_class
    foo = Deepthought::Deepthought.new
    assert_kind_of(Deepthought::Deepthought, foo, "")
  end

  def test_respond
    foo = Deepthought::Deepthought.new
    question = "The Ultimate Question of Life, the Universe and Everything"
    assert_equal(foo.respond(question), "42")
    question = "LOL"
    assert_equal(foo.respond(question), "Mmmm i'm bored")
  end

end