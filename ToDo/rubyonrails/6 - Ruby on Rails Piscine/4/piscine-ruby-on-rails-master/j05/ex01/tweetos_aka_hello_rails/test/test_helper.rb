ENV['RAILS_ENV'] ||= 'test'
require File.expand_path('../../config/environment', __FILE__)
require 'rails/test_help'

class ActiveSupport::TestCase
  # Setup all fixtures in test/fixtures/*.yml for all tests in alphabetical order.
  POPULATE = 'usr = User.new(name: "bob", email:"nope@yopmail.com" ,since:"1981", admin: true, country:"Groland",created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200") )
  usr.save!(validate: false)
  usr2 = User.new(name: "bob2", email:"nope2@yopmail.com" ,since:"1984", admin: true, country:"Groland",created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200") )
  usr2.save!(validate: false)
  cui = Cuicui.new(content:"hello" ,user_id:usr.id,created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200") )
  cui.save!(validate: false)
  like = Like.new(cuicui_id: cui.id, user_id: usr2.id, created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200"))
  like.save!(validate: false)
  comm = Comment.new(content: "hi!" ,cuicui_id: cui.id, user_id: usr2.id, created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200"))
  comm.save!(validate: false)
  comm2 = Comment.new(content: "I said hi!!", cuicui_id: cui.id, user_id: usr2.id, created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200"))
  comm2.save!(validate: false)'
  # Add more helper methods to be used by all tests here...
end
