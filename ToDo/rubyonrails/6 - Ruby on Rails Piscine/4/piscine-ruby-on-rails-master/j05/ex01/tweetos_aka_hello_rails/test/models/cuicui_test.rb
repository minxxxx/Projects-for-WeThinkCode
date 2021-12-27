require 'test_helper'

class CuicuiTest < ActiveSupport::TestCase
  test "test validation" do
    usr = User.new(name: "bob", email:"nope@yopmail.com" ,since:"1981", admin: true, country:"Groland",created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200") )
    usr.save!(validate: false)
    com = Comment.new(content:"hello" ,user_id:usr.id,created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200") )
    com.save!(validate: false)
    assert_raise ActiveRecord::RecordInvalid do
         Cuicui.create!
    end
    assert_raise ActiveRecord::RecordInvalid do
         Cuicui.create!(id:"a", content:"aa", user_id: usr.id)
    end
    assert_raise ActiveRecord::RecordInvalid do
         Cuicui.create!(id:1, content:"aa", user_id: usr.id)
         Cuicui.create!(id:2, content:"aa", user_id: usr.id)
    end
    assert_raise ActiveRecord::RecordInvalid do
         Cuicui.create!(id:1, content:"aa", user_id: 1000000)
    end
    assert_raise ActiveRecord::RecordInvalid do
         Cuicui.create!( content:"aa", user_id: usr.id)
    end
    assert_raise ActiveRecord::RecordInvalid do
         Cuicui.create!(id:1, user_id: usr.id)
    end
    assert_raise ActiveRecord::RecordInvalid do
         Cuicui.create!(id:1, content:"aa")
    end
  end
  test "testing the top scope" do
    20.times do |time|
      c = Cuicui.new(id:time, content:"#{time}", user_id: 1); c.save!(validate: false)
    end
    res = {6=>42, 16=>42, 5=>10, 15=>10, 3=>4, 13=>4, 2=>2,
       12=>2, 4=>1, 8=>1, 9=>1, 10=>1, 14=>1, 18=>1, 19=>1}
    lk = [0,2,4,1,10,42,0,1,1,1,0,2,4,1,10,42,0,1,1,1]
    lk.each_with_index do |nb, index|
      nb.times do |time|
        temp = Like.new(user_id:1, cuicui_id: index + 1)
        temp.save(validate: false)
      end
    end
    assert_equal(Cuicui.all.top.first.likes.count, 42)
    assert_equal(Cuicui.all.top.last.likes.count, 1)
    assert_kind_of(Cuicui::ActiveRecord_Relation,Cuicui.all.top )
    assert_kind_of(Array ,Cuicui.all.top.count.first)
    assert_kind_of(Hash ,Cuicui.all.top.count)
    assert_equal(Cuicui.all.top.count, res)
    assert_equal(Cuicui.all.top.size, res)

  end
end
