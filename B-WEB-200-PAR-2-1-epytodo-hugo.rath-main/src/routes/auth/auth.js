const { register, check_account_mail, get_mail_account } = require('./../user/user.query');

module.exports = function(app, bcrypt) {
  app.post('/login', (req, res) => {
    const { email, password } = req.body;

    if (!email || !password) {
      return res.status(500).json({ "msg": "internal server error" });
    }

    get_mail_account(res, email, password, bcrypt, function(nbr) {
      if (nbr === 84) {
        return res.status(401).json({ "msg": "Invalid Credentials" });
      }
      return;
    });
  });

  app.post('/register', (req, res) => {
    const { email, name, firstname, password } = req.body;

    if (!email || !name || !firstname || !password) {
      return res.status(500).json({ "msg": "internal server error" });
    }

    const hashedPassword = bcrypt.hashSync(password, 10);

    check_account_mail(res, email, function(nbr) {
      if (nbr === 84) {
        return res.status(409).json({ "msg": "account already exists" });
      } else {
        register(res, email, hashedPassword, name, firstname);
        return;
      }
    });
  });
};
