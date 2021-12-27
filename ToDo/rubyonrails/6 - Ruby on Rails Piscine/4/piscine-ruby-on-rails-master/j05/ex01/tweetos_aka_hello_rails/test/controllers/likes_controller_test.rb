require 'test_helper'

class LikesControllerTest < ActionController::TestCase
  test "Like's relations methods" do
    eval(POPULATE)
    test_like = Like.first
    foo = test_like.cuicui.content
    test_content = "hello"
    assert_equal(foo,test_content)
    assert_equal(test_like.user.name, "bob2")
  end
end
