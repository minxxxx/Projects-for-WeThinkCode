class RegisterController < ApplicationController
	before_action :is_not_connected

	def index

	end

	def register
		user = User.register(params[:email], params[:pseudo], params[:password], params[:password_confirmation])
		# check validation record
		valid_one = user.valid?
		# check message uncrypted length before save
		valid_length = User.check_password_length(user, params[:password], params[:password_confirmation])

		if valid_one && valid_length
			user.save
			session[:id] = user.id
			session[:pseudo] = user.pseudo
			session[:admin] = user.group == "admin"
			redirect_to "/home"
		else
			@error = user.errors.messages
			render template: "register/index"
		end
	end

	private

	def user_params
		params.permit(:email, :password, :password_confirmation)
	end
end
