require 'test_helper'
require 'pry'
class CommentTest < ActiveSupport::TestCase
test "test validation" do
  usr = User.new(name: "bob", email:"nope@yopmail.com" ,since:"1981", admin: true, country:"Groland",created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200") )
  usr.save!(validate: false)
  cui = Cuicui.new(content:"hello" ,user_id:usr.id,created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200") )
  cui.save!(validate: false)
   assert_raise ActiveRecord::RecordInvalid do
         Comment.create!
   end
   assert_raise ActiveRecord::RecordInvalid do
        Comment.create!(id: 1,content:"yessss" , cuicui_id:10000000, user_id:usr.id )
   end
   assert_raise ActiveRecord::RecordInvalid do
        Comment.create!(id: 1,content:"yessss" , cuicui_id:cui.id)
   end
   assert_raise ActiveRecord::RecordInvalid do
        Comment.create!(id: 1,content:"yessss" , cuicui_id:cui.id, user_id:10000000 )
   end
   assert_raise ActiveRecord::RecordInvalid do
        Comment.create!(content:"yessss" , cuicui_id:cui.id, user_id:usr.id )
   end
   assert_raise ActiveRecord::RecordInvalid do
        Comment.create!(id:1  , cuicui_id:cui.id, user_id:usr.id )
   end
   assert_raise ActiveRecord::RecordInvalid do
        Comment.create!(id:"a" ,content:"yessss" , cuicui_id:cui.id, user_id:usr.id )
   end
   assert_raise ActiveRecord::RecordInvalid do
        Comment.create!(id:1 ,content:"yessss" , cuicui_id:cui.id, user_id:usr.id )
        Comment.create!(id:2 ,content:"yessss" , cuicui_id:cui.id, user_id:usr.id )
   end
 end
end
