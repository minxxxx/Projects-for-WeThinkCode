class PagesController < ApplicationController

	def show
		@RandomAnimalName = PagesHelper.RandomAnimalName
		html_render()
	end

	def html_render
		if valid_page?
			render template: "pages/#{params[:page]}"
		else
			render file: "public/404.html", status: :not_found
		end
	end

	def logout
		# Remove the user id from the session
		session[:id] = nil
		session[:name] = nil
		redirect_to "/pages/home"
	end

	def login
		@error = nil
		if session[:id] != nil
			redirect_to "/pages/home"
			return
		end
		if request.post? == false
			return
		end
	    if user = User.authenticate(params[:username], params[:password])
			# Save the user ID in the session so it can be used in
			# subsequent requests
			session[:id] = user.id
			session[:name] = user.name
			redirect_to "/pages/home"
			return
		else
			@error = "Incorrect username or password"
			return
	    end
	end

	def register
		@error = nil
		if session[:id] != nil
			redirect_to "/pages/home"
			return
		end
		if request.post? == false
			return
		end
		if user = User.register(params[:name], params[:email], params[:password], params[:password_confirmation])
			if user.valid?
				user.save
				# Save the user ID in the session so it can be used in
				# subsequent requests
				session[:id] = user.id
				session[:name] = user.name
				redirect_to "/pages/home"
			else
				@error = user.errors.messages
			end
		end
	end

	private

	def valid_page?
		File.exist?(Pathname.new(Rails.root + "app/views/pages/#{params[:page]}.html.erb"))
	end
end
