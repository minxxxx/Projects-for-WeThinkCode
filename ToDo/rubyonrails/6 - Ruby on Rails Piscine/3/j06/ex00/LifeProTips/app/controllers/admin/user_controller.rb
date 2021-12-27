class Admin::UserController < ApplicationController
  before_action :authenticate_admin

  def users
    @users = User.all
  end

private
  def authenticate_admin
    if !@current_user || !@current_user.admin
      redirect_to root_path
    end
  end
end