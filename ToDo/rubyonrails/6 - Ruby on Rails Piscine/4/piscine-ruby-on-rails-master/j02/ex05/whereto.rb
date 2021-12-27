#! /usr/bin/ruby -W0

require_relative '../ex04/ex04.rb'

class Page
	attr_reader :element

	def initialize(element)
		if element.is_a?(Elem)
			@element = element
		else
			raise TypeError, "TypeError: Page arg is not instance of Elem !"
		end
	end

	def isvalid()
		puts "Currently evaluating a Html :"
		if @element.instance_of?(Html) == false
			return false
		end
		puts "- root element of type \"html\""
		hdr = false
		body = false
		tags = true
		puts "Evaluating a multiple node"
		#check Html head/body and valide tags of nodes
		element.content.each do |node|
			if node.kind_of?(Elem) == false
				tags = false
			end
			if node.instance_of?(Head)
				hdr = true
				if self.checkHead(node) == false
					return false
				end
			elsif node.instance_of?(Body) && hdr == true
				body = true
			end

			[Body,Div].any? do |klass|
				if node.instance_of?(klass)
					if self.checkContainer(node) == false
						return false
					end
				end
			end

			[Title,H1,H2,Li,Th,Td].any? do |klass|
				if node.instance_of?(klass)
					if (node.content.class == Array && node.content.size > 1 || node.content.class == Array && node.content[0].class != Text) || node.class != Text
						return false
					end
				end
			end

			[P].any? do |klass|
				if node.instance_of?(klass)
					if elementContainsUniquely(node, [Text]) == false
						return false
					end
				end
			end

			[Span].any? do |klass|
				if node.instance_of?(klass)
					valid = false
					if elementContainsUniquely(node, [Text]) == true || elementContainsUniquely(node, [P]) == true
						valid = true
					end
				end
			end

			[Ul,Ol].any? do |klass|
				if node.instance_of?(klass)
					valid = false
					if elementContainsUniquely(node, [Li]) == true
						valid = true
					end
					if node.content.class == Array && node.content.length == 0 || node.content.class != Li
						return false
					end
					if valid == false
						return false
					end
				end
			end
		end
		if hdr == false || body == false || tags == false
			return false
		end
		puts "- Html -> Must contains a Head AND a Body after it"
		puts "Nodes is OK"
		return true
	end

	def elementContainsUniquely(element, types)
		if element.content.class == Array
			element.content.each do |node|
				valid = false
				types.any? do |klass|
					if node.instance_of?(klass)
						valid = true
					end
				end
				if valid == false
					return false
				end
			end
		else
			types.any? do |klass|
				if element.content.instance_of?(klass)
					return 1
				end
			end
		end
		return nbr
	end

	def checkHead(head)
		if head == nil
			return false
		end
		if head.content.class != Array || head.content.length == 0
			return false
		end
		asTitle = false
		head.content.each do |node|
			if node.instance_of?(Title) == true && asTitle == true
				return false
			end
			if node.instance_of?(Title) == true
				asTitle = true
			end
		end
		puts "Head is OK"
		return true
	end

	def checkContainer(container)
		if container == nil
			return false
		end
		if container.content.class != Array
			return false
		end
		asTitle = false
		container.content.each do |node|
			valid = false
			[Img,H1,H2,Div,Table,Ul,Ol,Span,Text].any? do |klass|
				if node.instance_of?(klass)
					valid = true
				end
			end
			if valid == false
				return false
			end
		end
		puts "Container is OK"
		return true
	end
end

if $PROGRAM_NAME == __FILE__
	toto = Html.new([Head.new([Title.new(Text.new("Hello ground!"))]),
	Body.new([H1.new(Text.new("Oh no, not again!")), Img.new([],
	{'src' => Text.new('http://i.imgur.com/pfp3T.jpg')}) ]) ])
	test = Page.new(toto)
	puts test.isvalid()
	tata = Html.new([Head.new([Title.new(Text.new("Hello ground!"))]),
	Body.new([H1.new(Text.new("Oh no, not again!")), Img.new([],
	{'src' => Text.new('http://i.imgur.com/pfp3T.jpg')}) ]) ])
	test2 = Page.new(tata)
	puts test2.isvalid()
end