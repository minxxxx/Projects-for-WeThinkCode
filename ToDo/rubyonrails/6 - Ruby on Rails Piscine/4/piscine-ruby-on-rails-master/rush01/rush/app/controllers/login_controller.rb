class LoginController < ApplicationController
	before_action :is_not_connected

	def index
	end

	def login
		if user = User.authenticate(params[:email], params[:password])
			# Save the user ID in the session so it can be used in
			# subsequent requests
			session[:id] = user.id
			session[:pseudo] = user.pseudo
			session[:admin] = user.grp == 0
			redirect_to "/home"
			return
		else
			@error = "Incorrect username or password"
			render template: "login/index"
			return
	    end
	end
end
