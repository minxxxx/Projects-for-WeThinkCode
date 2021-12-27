Rails.application.routes.draw do

  match '/', :to => redirect("/home"), as: "home", via: [:get, :post]
  match '/home',		:controller => 'home', 		:action => 'index',		as: "home_route",		via: [:get, :post]

  # auth
  match '/login',		:controller => 'login', 	:action => 'index',		as: "login_route",		via: [:get]
  match '/login',		:controller => 'login', 	:action => 'login',		as: "login_post",		via: [:post]

  # logout
  match '/logout',		:controller => 'logout', 	:action => 'logout',	as: "logout_route",		via: [:get]

  # register
  match '/register',	:controller => 'register', 	:action => 'index',		as: "register_route",	via: [:get]
  match '/register',	:controller => 'register', 	:action => 'register',	as: "register_post",	via: [:post]

  # settings
  match '/setting',					:controller => 'setting', 	:action => 'index',		as: "setting_route",	 via: [:get]
  match '/setting/change_password',	:controller => 'setting', 	:action => 'pwd',		as: "setting_pwd_route", via: [:get]
  match '/setting/change_password',	:controller => 'setting', 	:action => 'pwd',		as: "setting_pwd_post", via: [:post]

  match '/administration', :controller => 'administration', :action => 'index', as: "administration_route", via: [:get]
  match '/administration/accounts', :controller => 'administration', :action => 'accounts', as: "administration_accounts_route", via: [:get]
  match '/administration/account/:id', :controller => 'administration', :action => 'account', as: "administration_account_route", via: [:get]
  match '/administration/account/:id', :controller => 'administration', :action => 'account', as: "administration_account_post", via: [:post]
  match '/administration/account/:id/remove', :controller => 'administration', :action => 'remove_account', as: "administration_account_remove_route", via: [:get, :post]

  # error
  match '*path',		:to => redirect("404.html"),	as: "error",	via: [:get]
end
