json.array!(@users) do |user|
  json.extract! user, :id, :lastname, :firstname, :email
  json.url user_url(user, format: :json)
end
