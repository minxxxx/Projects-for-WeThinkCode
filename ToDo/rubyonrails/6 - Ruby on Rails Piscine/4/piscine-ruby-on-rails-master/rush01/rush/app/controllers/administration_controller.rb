class AdministrationController < ApplicationController
	before_action :is_admin

	def index

	end

	def accounts
		@users = User.all
	end

	def account
		if @user = User.find_by(:id => params[:id])

		else
			redirect_to "/administration/accounts"
		end
	end

	def remove_account
		if @user = User.find_by(:id => params[:id])
			@user.destroy
			redirect_to "/administration/accounts"
		else
			redirect_to "/administration/accounts"
		end
	end
end
