Rails.application.routes.draw do

	# get '/page/:arg', to: 'page#action', as: "route_name"

	# ressources :page

	get '/vues/worldmap', to: 'game#index', as: 'worldmap'
	get '/vues/worldmap/:key', to: 'game#index'

	get '/vues/worldmap_start', to: 'game#start', as: 'worldmap_start'
	get '/vues/worldmap_start/:key', to: 'game#start'

	get '/vues/titlescreen', to: 'titlescreen#index', as: "titlescreen"
	get '/vues/titlescreen/:key', to: 'titlescreen#index'

	get '/vues/battle', to: 'battle#index', as: "battle"
	get '/vues/battle/:key', to: 'battle#index'

	get '/vues/moviedex', to: 'moviedex#index', as: "moviedex"
	get '/vues/moviedex/:key', to: 'moviedex#index'

	get '/vues/save_slot', to: 'saveslot#index', as: "saveslot"
	get '/vues/save_slot/:key', to: 'saveslot#index'
end
