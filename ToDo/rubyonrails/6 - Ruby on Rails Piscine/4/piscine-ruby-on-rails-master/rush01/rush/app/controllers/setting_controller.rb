class SettingController < ApplicationController
	before_action :is_connected, :get_user

	def index

	end

	def pwd
		return unless request.post?
		@valid_edit = true
		return unless @user.change_password(params[:last_password], params[:password], params[:password_confirmation]) == false
		@valid_edit = false
		@error = @user.errors.messages
	end

	private

	def get_user
		@user = User.find_by(:id => session[:id])
	end
end
