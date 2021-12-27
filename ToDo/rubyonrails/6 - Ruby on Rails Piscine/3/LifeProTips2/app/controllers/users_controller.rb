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
    @user = Users.new
  end

  def log_in
  end
  
  def create_user
    if params[:users][:mot2pass] == params[:users][:mot2pass_confirmation]
      @user = Users.new(users_params)
      if @user.save
        session[:user_id] = @user.id
        redirect_to root_path
      else
        render "sign_in"
      end
    else
      @user = Users.new(name: params[:users][:name], mot2pass: params[:users][:mot2pass], email: params[:users][:email])
      render "sign_in", notice: "Password don't match"
    end
  end
  
  def connect_user
    if params[:user][:mot2pass]
      params[:user][:mot2pass] = Digest::SHA2.hexdigest(params[:user][:mot2pass])
    end
    user = Users.find_by(user_connect_params)
    if user
      session[:user_id] = user.id
      redirect_to root_path
    else
      redirect_to log_in_path
    end
  end

  private
  def users_params
    params.require(:users).permit(:name, :email, :mot2pass)
  end
  def user_connect_params
    params.require(:user).permit(:email, :mot2pass)
  end
end