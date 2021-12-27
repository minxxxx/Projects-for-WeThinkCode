class User < ActiveRecord::Base
  before_save :encrypt_password
  validates_uniqueness_of :email
  validates_uniqueness_of :name
  validates :password, presence: true, length: { minimum: 8 }, on: :create
  validates :name, presence: true, on: :create
  validates :email, presence: true, on: :create

  def encrypt_password
    if password.present?
      self.password = Digest::SHA2.hexdigest(password)
    end
  end
end