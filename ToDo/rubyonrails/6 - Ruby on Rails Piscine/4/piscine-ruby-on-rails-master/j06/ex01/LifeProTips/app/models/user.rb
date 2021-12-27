require_dependency 'validators/email_validator.rb'

class User < ApplicationRecord

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

	def self.authenticate(username, password)
		return User.find_by(name: username, password: password)
	end

	def self.register(username, email, password, password_repeat)
		user = User.new(name: username, email: email, password: password, password_confirmation: password_repeat)
		return user
	end

	def self.install(username, email, password)
		user = User.new(name: username, email: email, password: password, password_confirmation: password)
		return user
	end

	def set_admin(boolean)
		update(:admin => boolean)
	end

end
