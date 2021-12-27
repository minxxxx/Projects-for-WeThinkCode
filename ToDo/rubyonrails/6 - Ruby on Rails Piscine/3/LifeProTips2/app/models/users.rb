class Users < ActiveRecord::Base
  before_save :encrypt_mot2pass
  validates_uniqueness_of :email
  validates_uniqueness_of :name
  validates :mot2pass, presence: true, length: { minimum: 8 }, on: :create
  validates :name, presence: true, on: :create
  validates :email, presence: true, on: :create

  def encrypt_password
    if mot2pass.present?
      self.mot2pass = Digest::SHA2.hexdigest(mot2pass)
    end
  end
end
