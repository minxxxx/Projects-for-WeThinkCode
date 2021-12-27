class ApplicationController < ActionController::Base
  protect_from_forgery with: :exception
  
	protected

	def is_connected
		if session[:id] == nil
			redirect_to "/home"
		end
	end

	def is_not_connected
		if session[:id] != nil
			redirect_to "/home"
		end
	end

	def is_admin
		if session[:id] == nil || session[:admin] == false
			redirect_to "/home"
		end
	end

end
