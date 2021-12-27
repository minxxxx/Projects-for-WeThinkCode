require 'test_helper'

class CommentsControllerTest < ActionController::TestCase
  test "Comment's relations methods" do
    eval(POPULATE)
    test_comment = Comment.first
    foo = test_comment.user.name
    assert_equal(foo, "bob2")
    cuicui_text = "hello"
    foo = test_comment.cuicui.content
    assert_equal(foo,cuicui_text)
  end
end
