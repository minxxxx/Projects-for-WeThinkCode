require "test_helper"

class DeepthoughtTest < Minitest::Test
  def test_that_it_has_a_version_number
    refute_nil ::Deepthought::VERSION
  end

  def test_that_it_has_constructor
  	assert_instance_of Deepthought, Deepthought.new
  end

  def test_check_response_one
  	assert_equal "42", Deepthought.new().respond("The Ultimate Question of Life, the Universe and Everything")
  end

  def test_check_response_two
  	assert_equal "Mmmm i'm bored", Deepthought.new().respond("Mmmm i'm bored")
  end
end
