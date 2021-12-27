class LogoutController < ApplicationController

	def logout
		session[:id] = nil
		session[:pseudo] = nil
		session[:admin] = nil
		redirect_to "/home"
	end

end
