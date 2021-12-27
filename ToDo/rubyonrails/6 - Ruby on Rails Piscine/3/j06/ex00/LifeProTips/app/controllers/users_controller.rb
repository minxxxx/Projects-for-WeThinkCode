require 'nokogiri'
require 'open-uri'

class UsersController < ApplicationController
  def index
    if !@current_user && !cookies[:animal]
      url = "https://www.randomlists.com/random-animals"
      doc = Nokogiri::HTML(open(url))
      animal = doc.css('li').first.css('span').text
      cookies[:animal] = { value: animal, expires: 1.minute.from_now }
    end
  end
  def sign_in
    @user = User.new
  end

  def log_in
  end

  def create_user
    if params[:user][:password] == params[:user][:password_confirmation]
      @user = User.new(user_params)
      if @user.save
        session[:user_id] = @user.id
        redirect_to root_path
      else
        render "sign_in"
      end
    else
      @user = User.new(name: params[:user][:name], password: params[:user][:password], email: params[:user][:email])
      @notice = "Passwords don't match"
      render "sign_in" 
    end
  end
  
  def connect_user
    if params[:user][:password]
      params[:user][:password] = Digest::SHA2.hexdigest(params[:user][:password])
    end
    user = User.find_by(user_connect_params)
    if user
      session[:user_id] = user.id
      redirect_to root_path
    else
      @notice = "Invalid User or Password"
      render "log_in"
    end
  end

  def log_out
    session[:user_id] = nil
    redirect_to root_path
  end

  private
  def user_params
    params.require(:user).permit(:name, :email, :password)
  end

  def user_connect_params
    params.require(:user).permit(:email, :password)
  end

end
