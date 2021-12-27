require 'test_helper'

class FtWikipediaTest < Minitest::Test
  def test_that_it_has_a_version_number
    refute_nil ::FtWikipedia::VERSION
  end

  def test_it_does_something_useful
    assert true
  end

  def test_it_works_with_kiss
    puts "================= test avec Kiss"
    FtWikipedia.search("Kiss")
  end

  def test_it_detects_loops_with_France
    puts "================= test avec France qui boucle"
    FtWikipedia.search("France")
  end

  def test_it_works_with_Einstein
    puts "================= test avec Einstein"
    FtWikipedia.search("Einstein")
  end

  def test_it_detects_dead_ends_with_PilouFilou
    puts "================= test avec PilouFilou qui pete"
    FtWikipedia.search("PilouFilou")
  end


end