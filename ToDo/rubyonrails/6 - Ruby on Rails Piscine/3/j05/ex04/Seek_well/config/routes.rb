Rails.application.routes.draw do
  root 'ft_query#index'
  post 'create_db' => 'ft_query#create_db'
  post 'insert_time_stamp' => 'ft_query#insert_time_stamp'
  post 'update_time_stamp' => 'ft_query#update_time_stamp'
  post 'create_table' => 'ft_query#create_table'
  post 'drop_table' => 'ft_query#drop_table'
  post 'delete_last' => 'ft_query#delete_last'
  post 'destroy_all' => 'ft_query#destroy_all'
  post 'start_race' => 'ft_query#start_race'
  post 'all_by_name' => 'ft_query#all_by_name'
  post 'all_by_race' => 'ft_query#all_by_race'
end
