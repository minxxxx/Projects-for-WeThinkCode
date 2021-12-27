# add fields on table
rails g add_column :users, :admin, :boolean, :default => true
# load les migrate charger
rails db:migrate RAILS_ENV=development
#
rails generate model User email:string pseudo:string password:string admin:boolean
# delete les bases
rm -rf db/*.sqlite3
# load le serveur puma
rails s



######################################
# MODEL UTILS
######################################

#PRESENCE
validates :name, :email, :password, :password_confirmation, presence: true
#UNIQUENESS
validates :name, :email, uniqueness: true

#length minimal of name field
validates :name, length: { minimum: 2 }

#email type of validation
validates :email, email: true

#confirmation password field and minimal length
validates :password, confirmation: true, length: { minimum: 8 }
validates :password_confirmation, length: { minimum: 8 }

######################################
