require 'test_helper'

class UserShowTest < ActionDispatch::IntegrationTest
  test "can see the user show page" do
      eval(POPULATE)
      get "/users/#{User.first.id}"
      assert_response :success
    end

end
