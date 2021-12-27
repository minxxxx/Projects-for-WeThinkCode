require 'test_helper'

class MigrationsTest < ActionController::TestCase
  test "Migrations methods" do
    eval(POPULATE)
  end
end