guard :shell do
  watch %r{^(src|include)/(.*)$} do
    `make clean && make`
  end
end
