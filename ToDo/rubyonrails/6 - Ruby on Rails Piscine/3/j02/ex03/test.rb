def foo(regular, hash={})
    puts "regular: #{regular}"
    puts "hash: #{hash}"
    puts "a: #{hash[:a]}"
    puts "b: #{hash[:b]}"
end

foo("regular argument", a: 12, :c => 13, b: 25)
