require 'test_helper'

class UsersSignupTest < ActionDispatch::IntegrationTest

  test "invalid lastname information" do
    get signup_path
    assert_no_difference 'User.count' do
      post users_path, params: { user: { lastname:  "",
                                         firstname:  "jeanpierre",
                                         username:  "jeanpierre",
                                         email: "user@invalid.com",
                                         password:              "foobar",
                                         password_confirmation: "foobar" } }
    end
    assert_template 'users/new'
  end
  test "invalid firstname information" do
    get signup_path
    assert_no_difference 'User.count' do
      post users_path, params: { user: { lastname:  "lastname",
                                           firstname:  "",
                                           username:  "jeanpierre",
                                           email: "user@invalid.com",
                                           password:              "foobar",
                                           password_confirmation: "foobar" } }
    end
    assert_template 'users/new'
  end
  test "invalid username information" do
    get signup_path
    assert_no_difference 'User.count' do
      post users_path, params: { user: { lastname:  "lastname",
                                         firstname:  "firstname",
                                         username:  "",
                                         email: "user@invalid.com",
                                         password:              "foobar",
                                         password_confirmation: "foobar" } }
    end
    assert_template 'users/new'
  end
  test "invalid email information" do
    get signup_path
    assert_no_difference 'User.count' do
      post users_path, params: { user: { lastname:  "lastname",
                                         firstname:  "firstname",
                                         username:  "toto1511",
                                         email: "",
                                         password:              "foobar",
                                         password_confirmation: "foobar" } }
    end
    assert_template 'users/new'
  end
  test "invalid password information" do
    get signup_path
    assert_no_difference 'User.count' do
      post users_path, params: { user: { lastname:  "lastname",
                                         firstname:  "firstname",
                                         username:  "toto1511",
                                         email: "user@invalid.com",
                                         password:              "",
                                         password_confirmation: "" } }
    end
    assert_template 'users/new'
  end
  test "different password information" do
    get signup_path
    assert_no_difference 'User.count' do
      post users_path, params: { user: { lastname:  "lastname",
                                         firstname:  "firstname",
                                         username:  "toto1511",
                                         email: "user@invalid.com",
                                         password:              "foobar",
                                         password_confirmation: "foobar2" } }
    end
    assert_template 'users/new'
  end
  test "valid signup information" do
    get signup_path
    assert_difference 'User.count', 1 do
      post users_path, params: { user: { lastname:  "lastname",
                                         firstname:  "firstname",
                                         username:  "toto1511",
                                         email: "user@invalid.com",
                                         password:              "foobar",
                                         password_confirmation: "foobar" } }
    end
    follow_redirect!
    assert_template 'users/show'
  end
end
