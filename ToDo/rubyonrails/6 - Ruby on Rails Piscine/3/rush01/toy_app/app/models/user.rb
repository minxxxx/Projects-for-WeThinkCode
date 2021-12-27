class User < ApplicationRecord
  has_many :microposts
  validates :lastname, presence: true
  validates :firstname, presence: true
  validates :email, presence: true
end
