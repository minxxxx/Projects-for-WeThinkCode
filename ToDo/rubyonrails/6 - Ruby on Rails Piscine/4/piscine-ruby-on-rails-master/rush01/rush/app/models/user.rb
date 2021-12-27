# require_dependency 'validators/email_validator.rb'
# require 'digest/sha1'

class User < ApplicationRecord

	validates :email, :pseudo, presence: true
	validates :email, :pseudo, uniqueness: true
	validates :pseudo, length: { minimum: 2 }
	validates :email, format: Devise.email_regexp

	validates :password, confirmation: true
	validates :password, length: { minimum: 8 }
	validates :password_confirmation, length: { minimum: 8 }

	enum grp: {
		admin: 0,
		nom_admin: 1
	}

	def self.authenticate(email, password)
		User.find_by(email: email, password: User.encrypt_pass(password))
	end

	def self.register(email, pseudo, password, password_confirmation)
		User.new(email: email, pseudo: pseudo, password: User.encrypt_pass(password), password_confirmation: User.encrypt_pass(password_confirmation))
	end

	def change_password(last_password, new_password, new_password_confirmation)
		res = true
		if last_password == nil || last_password == ""
			errors.messages[:last_password].push('can\'t be blank')
			res = false
		end
		if User.check_password_length(self, new_password, new_password_confirmation) == false
			res = false
		end
		if User.encrypt_pass(last_password) != password
			errors.messages[:last_password].push('incorrect last password')
			res = false
		end
		return res && update(:password => User.encrypt_pass(new_password), :password_confirmation => User.encrypt_pass(new_password_confirmation))
	end

	private

	def self.check_password_length(user, password, password_confirmation)
		res = true
		if password.length < 8
			user.errors.messages[:password].push('is too short (minimum is 8 characters)')
			res = false
		end
		if password_confirmation.length < 8
			user.errors.messages[:password_confirmation].push('is too short (minimum is 8 characters)')
			res = false
		end
		return res
	end

	def self.encrypt_pass(password)
		if password == nil || password == ""
			return ""
		end
		return Digest::SHA1.hexdigest(password)
	end

end
