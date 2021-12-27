require 'test_helper'

class UserTest < ActiveSupport::TestCase
  test "User validation" do
    assert_raise ActiveRecord::RecordInvalid do
         User.create!
    end
    assert_raise ActiveRecord::RecordInvalid do
         User.create!(id:1, name: "bob", email:"nopeyopmail.com" ,since:"1981", admin: true, country:"Groland",created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200"))
    end
    assert_raise ActiveRecord::RecordInvalid do
         User.create!(id:1, name: "bob", email:"nope@yopmail.com" ,since:"1981", admin: true, country:"Groland",created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200"))
         User.create!(id:2, name: "bob1", email:"nope@yopmail.com" ,since:"1981", admin: true, country:"Groland",created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200"))
    end
    assert_raise ActiveRecord::RecordInvalid do
         User.create!(id:1, name: "bob", email:"nope@yopmail.com" ,since:"1981", admin: true, country:"Groland",created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200"))
         User.create!(id:2, name: "bob", email:"nope1@yopmail.com" ,since:"1981", admin: true, country:"Groland",created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200"))
    end
    assert_raise ActiveRecord::RecordInvalid do
         User.create!(id:1, name: "bob" ,since:"1981", admin: true, country:"Groland",created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200"))
    end
    assert_raise ActiveRecord::RecordInvalid do
         User.create!(id:1, name: "bob", email:"nope@yopmail.com" , admin: true, country:"Groland",created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200"))
    end
    assert_raise ActiveRecord::RecordInvalid do
         User.create!(id:1, name: "bob", email:"nope@yopmail.com" ,since:"1981", admin: true,created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200"))
    end
    assert_raise ActiveRecord::RecordInvalid do
         User.create!( name: "bob", email:"nope@yopmail.com" ,since:"1981", admin: true, country:"Groland",created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200"))
    end
    assert_raise ActiveRecord::RecordInvalid do
         User.create!(id:1, email:"nope@yopmail.com" ,since:"1981", admin: true, country:"Groland",created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200"))
    end
    assert_raise ActiveRecord::RecordInvalid do
         User.create!(id:1, name: "bob",since:"1981", admin: true, country:"Groland",created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200"))
    end
    assert_raise ActiveRecord::RecordInvalid do
         User.create!(id:"a", name: "bob", email:"nope@yopmail.com" ,since:"1981", admin: true, country:"Groland",created_at: Time.parse("1981-07-15 03:34:42 +0200"), updated_at: Time.parse("1981-07-15 03:34:42 +0200"))
    end
  end
end
