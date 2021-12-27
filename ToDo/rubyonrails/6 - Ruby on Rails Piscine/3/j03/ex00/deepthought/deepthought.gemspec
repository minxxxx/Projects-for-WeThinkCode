# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'deepthought/version'

Gem::Specification.new do |spec|
  spec.name          = "deepthought"
  spec.version       = Deepthought::VERSION
  spec.authors       = ["jblancha"]
  spec.email         = [""]

  spec.summary       = " premier projet gems"
  spec.description   = " premier projet gems"
  spec.license       = "MIT"


  
  spec.bindir        = "exe"
  spec.executables   = spec.files.grep(%r{^exe/}) { |f| File.basename(f) }
  spec.require_paths = ["lib"]

  spec.add_development_dependency "bundler", "~> 1.14"
  spec.add_development_dependency "rake", "~> 10.0"
  spec.add_development_dependency "minitest", "~> 5.0"
  spec.add_development_dependency "colorize", "~> 0.8.1"
end
