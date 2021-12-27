# coding: utf-8
lib = File.expand_path("../lib", __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require "deepthought/version"

Gem::Specification.new do |spec|
  spec.name          = "deepthought"
  spec.version       = Deepthought::VERSION
  spec.authors       = ["jguyet"]
  spec.email         = ["jguyet@student.42.fr"]

  spec.summary       = %q{to get drunk}
  spec.description   = %q{blabla piscine ruby}
  spec.homepage      = ""
  spec.license       = "MIT"

  spec.files         = `git ls-files -z`.split("\x0").reject do |f|
    f.match(%r{^(test|spec|features)/})
  end
  spec.bindir        = "exe"
  spec.executables   = spec.files.grep(%r{^exe/}) { |f| File.basename(f) }
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.16"
  spec.add_development_dependency "rake", "~> 10.0"
  spec.add_development_dependency "minitest", "~> 5.0"
end
