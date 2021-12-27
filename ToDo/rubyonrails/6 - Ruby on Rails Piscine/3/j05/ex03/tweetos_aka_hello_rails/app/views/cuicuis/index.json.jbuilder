json.array!(@cuicuis) do |cuicui|
  json.extract! cuicui, :id, :content, :user_id
  json.url cuicui_url(cuicui, format: :json)
end
