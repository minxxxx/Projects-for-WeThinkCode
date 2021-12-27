Rails.application.routes.draw do
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html

	#if request is on / start pages controller and add params pageID
	#root "pages#show", page: "home"

	#subdomain redirect
	#root to: redirect(subdomain: 'foo', path: '/bar')

	#get "/admin", to: redirect("/admin/users")
	#get "/admin/:page" => "admin#users"

	#get "/users", to: redirect("/users/settings")
	#get "/users/:page" => "users#settings"

	#login route
	get "/pages/login" => "pages#login"
	post "/pages/login" => "pages#login"

	#logout route
	get "/pages/logout" => "pages#logout"
	post "/pages/logout" => "pages#logout"

	#register route
	get "/pages/register" => "pages#register"
	post "/pages/register" => "pages#register"

	#if request is on / redirect to /page/home
	root to: redirect("/pages/home")

	#if request is on /? redirect to /pages/home
	get "/:page", to: redirect("/pages/home")

	#/pages/pageID
	get "/pages/:page" => "pages#show"
	post "/pages/:page" => "pages#show"

	#all PATH afer /pages/pagename/*/*
	get "/pages/*page" => "pages#show"
	post "/pages/*page" => "pages#show"

	namespace :admin do
		resources :users
	end
end

##
# JGUYET Rails DOCUMENTATION ==>
##

##
#
# // Command for set on developement sqlite orm
#
# rm -f db/*.sqlite3
# rake db:create
# RAILS_ENV=development rake db:migrate
# rails s -e development
#
##

##
#
# rails g add_column :users, :admin, :boolean, :default => true
#
##
