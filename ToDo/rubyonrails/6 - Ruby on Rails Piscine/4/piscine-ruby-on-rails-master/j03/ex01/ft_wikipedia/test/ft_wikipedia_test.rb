require "test_helper"

class FtWikipediaTest < Minitest::Test
	def test_that_it_has_a_version_number
		refute_nil ::Ft_wikipedia::VERSION
	end

	def test_directory
		r = Ft_wikipedia.search("directory").to_s
		puts "=> " + r
		if r == "nil"
			assert true
		else
			assert false
		end
	end

	def test_problem
		r = Ft_wikipedia.search("problem").to_s
		puts "=> " + r
		if r == "nil"
			assert false
		else
			assert true
		end
	end

	def test_problem
		r = Ft_wikipedia.search("einstein").to_s
		puts "=> " + r
		if r == "nil"
			assert false
		else
			assert true
		end
	end

	def test_kiss
		r = Ft_wikipedia.search("kiss").to_s
		puts "=> " + r
		if r == "nil"
			assert false
		else
			assert true
		end
	end

	def test_matter
		r = Ft_wikipedia.search("matter").to_s
		puts "=> " + r
		if r == "nil"
			assert false
		else
			assert true
		end
	end

	def test_Error
		r = Ft_wikipedia.search("JFBFHFGFG").to_s
		puts "=> " + r
		if r == "nil"
			assert true
		else
			assert false
		end
	end
end
