require 'test_helper'

class MovieTest < Minitest::Test
  def test_that_it_has_a_version_number
    refute_nil ::Newmovie::VERSION
  end

  def test_it_does_something_useful
    assert true
  end
  def test_new
    puts "================= test new"
    #a = Newmovie.new
    #a.getmovies(3)
  end
  def test_save_session
    puts "================= test save_session"
    #a = Newmovie.new
    #a.getmovies(3)
    #a.save_session (1)
  end
  def test_load_session
    puts "================= test load_session"
    a = Newmovie.new
    a.getmovies(3)
    a.save_session (1)
    a.load_session (1)
  end
end
