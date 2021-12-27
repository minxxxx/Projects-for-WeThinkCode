class Admin::UsersController < ApplicationController
	before_action :require_admin

	def index
		render template: "admin/index"
	end

	private

	def require_admin
		if session[:id] == nil
			redirect_to "/pages/home"
			return
		end
		if session[:admin] == false
			redirect_to "/pages/home"
			return
		end
	end
end
