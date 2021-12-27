Rails.application.routes.draw do

  # books routes
  resources :books
  #match '/books',			:controller => 'books', :action => 'index',		as: "index_book",	via: [:get, :post]
  #match '/books/new',		:controller => 'books', :action => 'new',		as: "new_book",		via: [:get, :post]
  #match '/books/:id/edit',	:controller => 'books', :action => 'edit',		as: "edit_book",	via: [:get]
  #match '/books/:id',		:controller => 'books', :action => 'show',		as: "show_book",	via: [:get]
  #match '/books/:id',		:controller => 'books', :action => 'update',	as: "update_book",	via: [:patch, :put]
  #match '/books/:id',		:controller => 'books', :action => 'destroy',	as: "destroy_book",	via: [:delete]

  # redirect all unknown routes to 404.html
  match '*path',			:to => redirect('/404.html'),					as: "error",		via: [:get]
end
