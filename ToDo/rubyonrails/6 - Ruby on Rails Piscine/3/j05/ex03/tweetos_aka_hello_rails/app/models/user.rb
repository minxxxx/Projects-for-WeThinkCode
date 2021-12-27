class User < ActiveRecord::Base
  has_many :cuicuis
  has_many :likes
  has_many :comments
end