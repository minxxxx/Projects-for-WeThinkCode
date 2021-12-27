Rails.application.routes.draw do
  root 'users#index'
  get '/sign_in' => 'users#sign_in', as: 'sign_in'
  get '/log_in' => 'users#log_in', as: 'log_in'
  delete '/log_out' => 'users#log_out', as: 'log_out'
  post '/user/connect' => 'users#connect_user', as: 'connect_user'
  post '/users/create' => 'users#create_user', as: 'create_user'
  get '/user/edit/:id' => 'user#edit', as: 'user_edit'
  match '/user/update/:id' => 'user#update', as: 'user_update', via: [:get, :post]
  namespace :admin do
    get '/users' => 'user#users', as: 'users'
  end
  # The priority is based upon order of creation: first created -> highest priority.
  # See how all your routes lay out with "rake routes".

  # You can have the root of your site routed with "root"
  # root 'welcome#index'

  # Example of regular route:
  #   get 'products/:id' => 'catalog#view'

  # Example of named route that can be invoked with purchase_url(id: product.id)
  #   get 'products/:id/purchase' => 'catalog#purchase', as: :purchase

  # Example resource route (maps HTTP verbs to controller actions automatically):
  #   resources :products

  # Example resource route with options:
  #   resources :products do
  #     member do
  #       get 'short'
  #       post 'toggle'
  #     end
  #
  #     collection do
  #       get 'sold'
  #     end
  #   end

  # Example resource route with sub-resources:
  #   resources :products do
  #     resources :comments, :sales
  #     resource :seller
  #   end

  # Example resource route with more complex sub-resources:
  #   resources :products do
  #     resources :comments
  #     resources :sales do
  #       get 'recent', on: :collection
  #     end
  #   end

  # Example resource route with concerns:
  #   concern :toggleable do
  #     post 'toggle'
  #   end
  #   resources :posts, concerns: :toggleable
  #   resources :photos, concerns: :toggleable

  # Example resource route within a namespace:
  #   namespace :admin do
  #     # Directs /admin/products/* to Admin::ProductsController
  #     # (app/controllers/admin/products_controller.rb)
  #     resources :products
  #   end
end
